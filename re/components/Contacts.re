[@react.component]
let make = (~contacts: list(Page.Employee.t), ~title=None) => {
  <div className="grid grid-columns-4 grid-gap-8-x">
    {switch (title) {
     | None => React.null
     | Some(title) => <div> title->React.string </div>
     }}
    {contacts
     ->Belt.List.map(({title, avatar, email, name}) =>
         <div className="text-center">
           <div> title->React.string </div>
           {switch (avatar) {
            | None => React.null
            | Some(src) => <img src alt="" />
            }}
           <div> name->React.string </div>
           email->React.string
         </div>
       )
     ->Belt.List.toArray
     ->React.array}
  </div>;
};
