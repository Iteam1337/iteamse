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

  let code =
    [Up, Up, Down, Down, Left, Right, Left, Right, B, A]->Belt.List.reverse;

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

      document
      |> Document.asEventTarget
      |> EventTarget.addKeyUpEventListener(handleKeyUp);

      Some(
        () =>
          document
          |> Document.asEventTarget
          |> EventTarget.removeKeyUpEventListener(handleKeyUp),
      );
    });
  };
};
