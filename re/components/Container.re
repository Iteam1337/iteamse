[@react.component]
let make = (~className=?, ~children) => {
  Web.(
    EasterEggs.Konami.useCode(
      ~success=
        _ =>
          switch (Document.element) {
          | Some(el) => el->ClassName.add("comic-sans")
          | None => ()
          },
      ~reset=
        _ =>
          switch (Document.element) {
          | Some(el) => el->ClassName.remove("comic-sans")
          | None => ()
          },
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
