[@react.component]
let make = (~contacts: list(Page.Employee.t), ~title=None) => {
  <div className="grid md:grid-columns-4 grid-gap-8-x">
    {switch (title) {
     | None => React.null
     | Some(title) => <Typography.H2> title </Typography.H2>
     }}
    {contacts
     ->Belt.List.map(({title, avatar, email, name}) =>
         <div className="flex flex-col items-center text-center">
           <div className="font-medium mb-5"> title->React.string </div>
           {switch (avatar) {
            | None => <Avatar.Gravatar email />
            | Some(src) => <Avatar.Contentful src />
            }}
           <div className="font-medium mt-5"> name->React.string </div>
           <Mailto email />
         </div>
       )
     ->Belt.List.toArray
     ->React.array}
  </div>;
};
