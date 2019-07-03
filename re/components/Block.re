module Markdown = {
  [@bs.module] [@react.component]
  external make: (~source: string) => React.element = "react-markdown";
};

module Text = {
  let className =
    Css.(
      style([
        display(`grid),
        gridTemplateColumns([`px(320), `fr(1.0)]),
        gridColumn(2, 2),
        gridColumnGap(`px(60)),
        media(
          Theme.Breakpoints.fromType(`Mobile),
          [gridTemplateColumns([`fr(1.0)]), gridRowGap(`px(10))],
        ),
      ])
    );

  [@react.component]
  let make = (~title, ~children) => {
    <section className>
      <Typography.H2> title </Typography.H2>
      <div> <Markdown source=children /> </div>
    </section>;
  };
};

module Illustration = {
  let className =
    Css.(
      style([
        display(`grid),
        gridTemplateColumns([`repeat((`num(12), `fr(1.0)))]),
        gridColumn(2, 2),
        media(
          Theme.Breakpoints.fromType(`Mobile),
          [display(`flex), justifyContent(`center)],
        ),
      ])
    );

  let imgClassName =
    Css.(
      style([
        unsafe("grid-column", "6 / auto"),
        maxWidth(`none),
        media(
          Theme.Breakpoints.fromType(`Mobile),
          [maxWidth(`percent(90.0))],
        ),
      ])
    );

  [@react.component]
  let make = (~src) => {
    <div className> <img className=imgClassName src alt="" /> </div>;
  };
};

module Section = {
  [@react.component]
  let make = (~color as c, ~children) => {
    let className =
      Css.(
        style([
          backgroundColor(Theme.Colors.fromType(c)),
          color(
            switch (c) {
            | `CornflowerBlue
            | `RadicalRed => `hex("fff")
            | _ => `hex("000")
            },
          ),
          gridColumn(-1, 1),
          display(`grid),
          gridTemplateColumns([`fr(1.0), `px(1024), `fr(1.0)]),
          padding2(~v=`px(100), ~h=`zero),
          selector("> *", [gridColumn(2, 2)]),
        ])
      );

    <div className> children </div>;
  };
};
