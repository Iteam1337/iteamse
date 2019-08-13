module Link = {
  [@bs.module "gatsby-link"] [@react.component]
  external make:
    (~className: option(string), ~_to: string, ~children: React.element) =>
    React.element =
    "default";
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
