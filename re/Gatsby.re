module Link = {
  [@bs.module "gatsby-link"] [@react.component]
  external make:
    (~className: option(string), ~_to: string, ~children: React.element) =>
    React.element =
    "default";
};
