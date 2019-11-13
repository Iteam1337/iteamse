module JsWindow = {
  [@bs.val] [@bs.scope ("window", "location")]
  external location: string = "pathname";
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

  let (parts, setUrlParts) = React.useState(() => None);

  React.useEffect0(() => {
    let parts =
      Js.String.split("/", JsWindow.location)
      ->Belt.List.fromArray
      ->Belt.List.tail
      ->Belt.Option.getWithDefault([])
      ->Belt.List.keep(p => p != "");

    Js.log(parts->Belt.List.toArray);

    setUrlParts(_prevParts => Some(parts));

    None;
  });

  <div className="grid-gap-2-y grid md:grid-columns-12 grid-gap-8-x">
    <div className=Css.(merge([separator, "md:col-start-1 md:col-end-12"]))>
      {parts
       ->Belt.Option.getWithDefault([])
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
