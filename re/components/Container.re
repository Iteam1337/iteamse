[@react.component]
let make = (~className=?, ~children) => {
  Web.(
    EasterEggs.Konami.useCode(
      ~success=_ => Document.element->ClassName.add("comic-sans"),
      ~reset=_ => Document.element->ClassName.remove("comic-sans"),
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
