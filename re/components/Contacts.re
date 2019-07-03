module Style = {
  open Css;

  let wrap =
    style([
      display(`grid),
      gridTemplateColumns([`repeat((`num(4), `fr(1.0)))]),
    ]);

  let employee = style([textAlign(`center)]);
};

[@react.component]
let make = (~employees: array(Types.employee), ~title=None) => {
  <div className=Style.wrap>
    {switch (title) {
     | None => React.null
     | Some(title) => <div> title->React.string </div>
     }}
    {employees
     ->Belt.Array.map(employee =>
         <div className=Style.employee>
           <div> {employee##title->React.string} </div>
           {switch (employee##avatar->Js.Nullable.toOption) {
            | None => React.null
            | Some(src) => <img src={src##file##url} alt="" />
            }}
           <div> {employee##name->React.string} </div>
           {employee##email->React.string}
         </div>
       )
     ->React.array}
  </div>;
};
