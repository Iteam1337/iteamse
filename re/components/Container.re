[@react.component]
let make = (~className=?, ~children) => {
  <main
    className={Css.merge([
      "grid-columns-iteam grid-gap-10-y grid md:grid-gap-24-y my-10 md:my-24",
      className->Cn.unpack,
    ])}>
    children
  </main>;
};
