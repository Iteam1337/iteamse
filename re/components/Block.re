module Markdown = {
  module Parse = {
    [@bs.module "react-html-parser"]
    external make: string => React.element = "default";
  };

  module Dedent = {
    [@bs.module] external make: string => string = "dedent";
  };

  module Generate = {
    [@bs.module] external make: string => string = "marked";
  };

  [@react.component]
  let make = (~source, ~className=?) => {
    <div className={Cn.make(["markdown", className->Cn.unpack])}>
      {source->Dedent.make->Generate.make->Parse.make}
    </div>;
  };
};

module Header = {
  [@react.component]
  let make =
      (
        ~backgroundImage as bg,
        ~backgroundFluid=None,
        ~color as c,
        ~textColor as _tc=?,
        ~messageOne,
        ~messageTwo=None,
        ~messageTwoLight=false,
        ~navColor=`White,
        ~navStyle=`Default,
      ) => {
    let marker = Css.merge(["px-2 py-1", Theme.Colors.fromType(c)]);
    let navigationBackground =
      Css.(
        merge([
          "md:grid md:grid-columns-1024 flex flex-col col-bleed absolute inset-0
          tablet:px-4 items-start",
          style([
            backgroundImage(
              linearGradient(
                `deg(180.0),
                [
                  (`px(0), `rgba((0, 0, 0, 0.3))),
                  (`px(100), `rgba((0, 0, 0, 0.0))),
                ],
              ),
            ),
            // Safari fix
            media(
              "not all and (min-resolution:.001dpcm)",
              [gridTemplateRows([`px(95), `px(705)])],
            ),
          ]),
        ])
      );

    let transition =
      Css.(
        style([
          after([
            contentRule(""),
            display(`block),
            height(`px(200)),
            position(`absolute),
            bottom(`px(0)),
            left(`px(0)),
            right(`px(0)),
          ]),
        ])
      );

    <header
      className={Css.merge([
        "grid md:grid-columns-1024 grid-columns-1fr bg-top bg-cover lg:h-jumbo
        h-md relative overflow-hidden",
        transition,
      ])}>
      {switch (backgroundFluid) {
       | Some(fluid) =>
         <Gatsby.FluidImg className={Some("col-bleed")} fluid />
       | None =>
         <img
           className="col-bleed w-full h-full object-cover"
           alt="Header"
           src=bg
         />
       }}
      <div className=navigationBackground>
        <Navigation color=navColor navStyle />
        <div
          className="md:col-start-3 md:self-end lg:pb-20 pb-8
        tablet-landscape:px-5">
          <Typography.H1>
            <span className=marker> messageOne->React.string </span>
            {messageTwo
             ->Belt.Option.map(message =>
                 <>
                   <div className="mt-1" />
                   <span
                     className={Css.merge([
                       marker,
                       "font-light"->Cn.ifTrue(messageTwoLight),
                     ])}>
                     message->React.string
                   </span>
                 </>
               )
             ->Belt.Option.getWithDefault(React.null)}
          </Typography.H1>
        </div>
      </div>
    </header>;
  };
};

module CaseHeader = {
  [@react.component]
  let make = (~backgroundImage as bg, ~backgroundFluid=None) => {
    let navigationBackground =
      Css.(
        merge([
          style([
            backgroundImage(
              linearGradient(
                `deg(180.0),
                [
                  (`px(0), `rgba((0, 0, 0, 0.3))),
                  (`px(100), `rgba((0, 0, 0, 0.0))),
                ],
              ),
            ),
          ]),
          "grid md:grid-columns-1024 col-bleed absolute inset-0 tablet:px-4",
        ])
      );

    <header
      className={Css.merge([
        "grid md:grid-columns-1024 grid-columns-1fr bg-top bg-cover md:h-16
        relative overflow-hidden h-1/3 md:h-1/3",
      ])}>
      {switch (backgroundFluid) {
       | Some(fluid) =>
         <Gatsby.FluidImg className={Some("col-bleed")} fluid />
       | None => <img className="col-bleed w-full" alt="Header" src=bg />
       }}
      <div className=navigationBackground> <Navigation /> </div>
    </header>;
  };
};

module StartpageHeader = {
  let bgImage = imageUrl => Css.(style([backgroundImage(`url(imageUrl))]));

  [@react.component]
  let make = (~title, ~lead, ~illustrationIteamI, ~backgroundImage as bg) => {
    <header
      className=Css.(
        merge([
          "grid lg:grid-columns-1024 tablet:px-4 grid-columns-1fr bg-no-repeat md:h-startpage2019
          sm:h-md",
          style([
            media(
              Theme.Breakpoints.fromType(`Desktop),
              [
                backgroundPosition(vw(40.), px(-160)),
                unsafe("backgroundSize", "940px"),
              ],
            ),
            media(
              Theme.Breakpoints.fromType(`Tablet),
              [
                backgroundPosition(pct(175.), pct(100.)),
                unsafe("backgroundSize", "80%"),
              ],
            ),
            media(
              Theme.Breakpoints.fromType(`Mobile),
              [
                backgroundPosition(px(-140), `px(-170)),
                unsafe("backgroundSize", "640px"),
              ],
            ),
          ]),
          bgImage(bg),
        ])
      )>
      <div className="grid md:grid-columns-1024 col-bleed">
        <Navigation color=`Black />
        <div
          className="md:col-start-3 self-end md:pb-20 startpage2019 flex mobile:flex-col-reverse
          lg:flex-row tablet-landscape:px-5 mobile:items-center">
          <div
            className="flex items-start justify-center flex-col sm:w-3/5 mobile:pt-8">
            <h1 className="md:text-3xl font-light text-2xl md:mb-12 mb-8">
              title->React.string
            </h1>
            <Markdown
              source=lead
              className=Css.(style([important(fontSize(px(20)))]))
            />
          </div>
          <img
            src=illustrationIteamI
            className=Css.(
              merge([
                "tablet:w-48 tablet:p-4 sm:flex-1",
                style([
                  media(
                    Theme.Breakpoints.fromType(`Mobile),
                    [important(width(`vw(66.0)))],
                  ),
                ]),
              ])
            )
            alt="The I in Iteam as a construction-site illustration"
          />
        </div>
      </div>
    </header>;
  };
};

module Text = {
  [@react.component]
  let make = (~title, ~children as source, ~subtitle=?) => {
    <section className="grid-gap-2-y grid md:grid-columns-12 grid-gap-8-x">
      <div className="md:col-start-1 md:col-end-5">
        <Typography.H2> title </Typography.H2>
        {subtitle
         ->Belt.Option.map(s =>
             <span className="text-lg"> s->React.string </span>
           )
         ->Belt.Option.getWithDefault(React.null)}
      </div>
      <div className="md:col-start-5 md:col-end-13"> <Markdown source /> </div>
    </section>;
  };
};

module Element = {
  type title = [ | `Text(string) | `Image(React.element)];

  [@react.component]
  let make = (~title, ~children, ~subtitle=?) => {
    <section className="grid-gap-2-y grid md:grid-columns-12 grid-gap-8-x">
      <div className="md:col-start-1 md:col-end-5">
        {switch (title) {
         | `Text(text) => <Typography.H2> text </Typography.H2>
         | `Image(imageEl) => imageEl
         }}
        {subtitle
         ->Belt.Option.map(s =>
             <span className="text-lg"> s->React.string </span>
           )
         ->Belt.Option.getWithDefault(React.null)}
      </div>
      <div className="md:col-start-5 md:col-end-13"> children </div>
    </section>;
  };
};

module Case = {
  type title = [ | `Text(string) | `Image(React.element)];

  [@react.component]
  let make = (~title, ~children, ~subtitle=?) => {
    let isText =
      switch (title) {
      | `Text(_) => true
      | _ => false
      };

    <section className="flex flex-col items-center">
      <div className={isText ? "self-start mb-4" : "mb-16"}>
        {switch (title) {
         | `Text(text) => <Typography.H3> text </Typography.H3>
         | `Image(imageEl) => imageEl
         }}
        {subtitle
         ->Belt.Option.map(s =>
             <span className="text-lg"> s->React.string </span>
           )
         ->Belt.Option.getWithDefault(React.null)}
      </div>
      <div> children </div>
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
  let make = (~color as c, ~children, ~className=?) => {
    <div
      className={Css.merge([
        "grid-columns-iteam grid py-10 md:py-24 col-bleed",
        Theme.Colors.fromType(c),
        Cn.unpack(className),
      ])}>
      children
    </div>;
  };
};

module CTA = {
  [@react.component]
  let make = (~button, ~title, ~children, ~illustration) => {
    <div className="grid-gap-2-y grid md:grid-columns-12">
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
