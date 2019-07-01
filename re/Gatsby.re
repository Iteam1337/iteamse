module Link = {
  [@bs.module "gatsby-link"] [@react.component]
  external make: (~_to: string, ~children: React.element) => React.element =
    "default";
};

/*module type Config = {*/
/*let query: string;*/
/*type t;*/
/*let parse: Js.Json.t => t;*/
/*};*/

/*type queryString;*/
/*type gql = (. string) => queryString;*/

/*module Query = (Config: Config) => {*/
/*[@bs.module "gatsby"] external gql: gql = "graphql";*/

/*let graphqlQueryAST = gql(. Config.query);*/

/*[@bs.module "gatsby"]*/
/*external _useStaticQuery: queryString => string = "useStaticQuery";*/

/*let use = () => _useStaticQuery(graphqlQueryAST);*/
/*};*/
