module Markdown = {
  [@bs.module] [@react.component]
  external make: (~source: string) => React.element = "react-markdown";
};

module Text = {
  [@react.component]
  let make = (~title, ~children as source) => {
    <section className="grid-gap-2-y grid md:grid-columns-12">
      <div className="md:col-start-1 md:col-end-5">
        <Typography.H2> title </Typography.H2>
      </div>
      <div className="md:col-start-5 md:col-end-13"> <Markdown source /> </div>
    </section>;
  };
};

module Illustration = {
  [@react.component]
  let make = (~src) => {
    <div
      className="flex justify-center md:grid grid-columns-12 col-start-2 col-end-2">
      <img className="max-w-xs col-start-6 md:max-w-initial" src alt="" />
    </div>;
  };
};

module Section = {
  [@react.component]
  let make = (~color as c, ~children) => {
    <div
      className={Css.merge([
        "grid py-24 grid-columns-1024 col-bleed",
        Theme.Colors.fromType(c),
      ])}>
      children
    </div>;
  };
};
