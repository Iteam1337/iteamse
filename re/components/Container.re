[@react.component]
let make = (~className=?, ~children) => {
  Webapi.Dom.(
    EasterEggs.Konami.useCode(
      ~success=
        _ =>
          document
          |> Document.documentElement
          |> Element.classList
          |> DomTokenList.add("comic-sans"),
      ~reset=
        _ =>
          document
          |> Document.documentElement
          |> Element.classList
          |> DomTokenList.remove("comic-sans"),
    )
  );

  <main
    className={Css.merge([
      "grid-columns-iteam grid-gap-10-y grid md:grid-gap-24-y my-10 md:my-24",
      className->Cn.unpack,
    ])}>
    children
  </main>;
};
