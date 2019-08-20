module JsWindow = {
  [@bs.val] [@bs.scope ("window", "location")]
  external location: string = "pathname";
};

/* TODO: Implemented in OCaml 4.05, remove when BuckleScript-version is updated */
let split_on_char = (sep, s) => {
  open String;
  let r = ref([]);
  let j = ref(length(s));
  for (i in length(s) - 1 downto 0) {
    if (unsafe_get(s, i) == sep) {
      r := [sub(s, i + 1, j^ - i - 1), ...r^];
      j := i;
    };
  };
  [sub(s, 0, j^), ...r^];
};

let parseSlug =
  fun
  | "karriar" => Some({js|Karriär|js})
  | "medarbetare" => Some({js|Medarbetare|js})
  | "case" => Some({js|Case|js})
  | _ => None;

[@react.component]
let make = (~title) => {
  let separator =
    Css.(
      style([
        selector(
          "> :not(:last-child):after",
          [
            fontWeight(`num(300)),
            contentRule("/"),
            marginLeft(`px(5)),
            marginRight(`px(5)),
            display(`inlineBlock),
          ],
        ),
        selector("span:last-of-type", [fontWeight(`num(500))]),
      ])
    );

  let parts = JsWindow.location |> split_on_char('/') |> List.tl;

  <div className="grid-gap-2-y grid md:grid-columns-12 grid-gap-8-x">
    <div className=Css.(merge([separator, "md:col-start-1 md:col-end-12"]))>
      {parts
       ->Belt.List.map(p =>
           <span key=p>
             {parseSlug(p)
              ->Belt.Option.map(link =>
                  <Gatsby.Link className=None _to=p>
                    link->React.string
                  </Gatsby.Link>
                )
              ->Belt.Option.getWithDefault({j|$title|j}->React.string)}
           </span>
         )
       ->Belt.List.toArray
       ->React.array}
    </div>
  </div>;
};
