module LinkInternal = {
  [@bs.module "gatsby-link"] [@react.component]
  external make:
    (~className: option(string), ~_to: string, ~children: React.element) =>
    React.element =
    "default";
};

module Link = {
  [@react.component]
  let make =
      (
        ~ariaLabel: string,
        ~className: option(string),
        ~_to: string,
        ~children: React.element,
      ) => {
    ReasonReact.cloneElement(
      <LinkInternal className _to> children </LinkInternal>,
      ~props={"aria-label": ariaLabel},
      [||],
    );
  };
};

module FluidImg = {
  [@bs.module "gatsby-image"] [@react.component]
  external make:
    (~className: option(string), ~fluid: Js.t('a)) => React.element =
    "default";
};

module FixedImg = {
  [@bs.module "gatsby-image"] [@react.component]
  external make:
    (~className: option(string), ~fixed: Js.t('a)) => React.element =
    "default";
};
