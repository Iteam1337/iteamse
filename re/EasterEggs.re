module Konami = {
  open Webapi.Dom;

  type t =
    | A
    | B
    | Down
    | Left
    | Right
    | Up;

  type state = list(t);

  type action =
    | ResetStyling
    | ClearKeys
    | StoreKey(t);

  // Konami code in reverse
  let code = [A, B, Right, Left, Right, Left, Down, Down, Up, Up];

  let rec testKonamiCode = (keys, iter) => {
    switch (keys, iter) {
    | ([], 0) => false
    | ([], _) => true
    | ([head, ...tail], _) =>
      switch (code->Belt.List.get(iter)) {
      | Some(v) => v === head ? testKonamiCode(tail, iter + 1) : false
      | None => false
      }
    };
  };

  let useCode = (~success, ~reset) => {
    let (storedKeys, dispatch) =
      React.useReducer(
        (storedKeys, action) =>
          switch (action) {
          | ResetStyling =>
            reset();
            storedKeys;
          | ClearKeys => []
          | StoreKey(key) => [key, ...storedKeys]
          },
        [],
      );

    React.useEffect1(
      () => {
        if (testKonamiCode(storedKeys, 0)) {
          success();
          dispatch(ClearKeys);
        };

        None;
      },
      [|storedKeys|],
    );

    React.useEffect0(() => {
      let handleKeyUp = event => {
        switch (event |> KeyboardEvent.key) {
        | "a" => dispatch(StoreKey(A))
        | "b" => dispatch(StoreKey(B))
        | "q" => dispatch(ResetStyling)
        | "ArrowUp" => dispatch(StoreKey(Up))
        | "ArrowDown" => dispatch(StoreKey(Down))
        | "ArrowLeft" => dispatch(StoreKey(Left))
        | "ArrowRight" => dispatch(StoreKey(Right))
        | "Escape" => dispatch(ClearKeys)
        | _ => ()
        };
      };

      Web.Keyboard.addKeyUpListener(handleKeyUp);

      Some(() => Web.Keyboard.removeKeyUpListener(handleKeyUp));
    });
  };
};
