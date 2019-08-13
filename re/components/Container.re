[@react.component]
let make = (~className=?, ~children) => {
  <main
    className={Css.merge([
      "grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-12 md:my-24",
      className->Cn.unpack,
    ])}>
    children
  </main>;
};
