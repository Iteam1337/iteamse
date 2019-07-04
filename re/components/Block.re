module Markdown = {
  [@bs.module] [@react.component]
  external make: (~source: string) => React.element = "react-markdown";
};

module Header = {
  let bgImage = imageUrl => Css.(style([backgroundImage(`url(imageUrl))]));

  [@react.component]
  let make = (~backgroundImage, ~children) => {
    <header
      className={Css.merge([
        "grid md:grid-columns-1024 grid-columns-1fr bg-top bg-cover md:h-jumbo h-md",
        bgImage(backgroundImage),
      ])}>
      <div className="col-start-2 self-end md:pb-20 pb-8"> children </div>
    </header>;
  };
};

module Text = {
  [@react.component]
  let make = (~title, ~children as source) => {
    <section
      className="grid-gap-2-y grid md:grid-columns-12 col-start-2
      col-end-2 grid-gap-8-x">
      <div className="md:col-start-1 md:col-end-5">
        <Typography.H2> title </Typography.H2>
      </div>
      <div className="md:col-start-5 md:col-end-13"> <Markdown source /> </div>
    </section>;
  };
};

module Element = {
  [@react.component]
  let make = (~title, ~children) => {
    <section
      className="grid-gap-2-y grid md:grid-columns-12 col-start-2
      col-end-2 grid-gap-8-x">
      <div className="md:col-start-1 md:col-end-5">
        <Typography.H2> title </Typography.H2>
      </div>
      <div className="md:col-start-5 md:col-end-13"> children </div>
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
        "grid-columns-1fr grid py-24 md:grid-columns-1024 col-bleed",
        Theme.Colors.fromType(c),
      ])}>
      children
    </div>;
  };
};

module CTA = {
  [@react.component]
  let make = (~button, ~title, ~children, ~illustration) => {
    <div
      className="grid-gap-2-y grid md:grid-columns-12 col-start-2 col-end-2">
      <div className="md:col-start-1 md:col-end-5">
        <img src=illustration alt="" />
      </div>
      <div className="md:col-start-5 md:col-end-13">
        <Typography.H2> title </Typography.H2>
        <p className="pt-2 pb-10"> children->React.string </p>
        <Button.Secondary href="mailto:info@iteam.se">
          button
        </Button.Secondary>
      </div>
    </div>;
  };
};

module Image = {
  [@react.component]
  let make = (~src) => {
    <img className="col-bleed w-full" src alt="" />;
  };
};
