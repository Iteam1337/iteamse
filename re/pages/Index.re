let text = ReasonReact.string;

type t = {
  .
  "weAreTitle": string,
  "weAreText": {. "weAreText": string},
};

[@react.component]
let make = (~data: t) => {
  <div>
    <div> {text(data##weAreText##weAreText)} </div>
    <div> {text(data##weAreTitle)} </div>
  </div>;
};

let default = make;
