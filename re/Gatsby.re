module Link = {
  [@bs.module "gatsby-link"] [@react.component]
  external make: (~_to: string, ~children: React.element) => React.element =
    "default";
};
