[@react.component]
let make = (~contacts: list(Page.Employee.t), ~title=?) => {
  <div className="col-start-2 col-end-2">
    {switch (title) {
     | None => React.null
     | Some(title) =>
       <div className="mb-12"> <Typography.H2> title </Typography.H2> </div>
     }}
    {switch (Belt.List.length(contacts)) {
     | 2 =>
       <div
         className="grid md:grid-columns-2 grid-gap-8-x grid-gap-4-y col-start-2 col-end-2">
         {contacts
          ->Belt.List.map(({title, avatar, email, name, phoneNumber}) =>
              <div
                className="grid md:grid-columns-10 items-center
              justify-center text-center md:text-left">
                <div className="md:col-start-1 md:col-end-6">
                  {switch (avatar) {
                   | None => <Avatar.Gravatar email />
                   | Some(src) => <Avatar.Contentful src />
                   }}
                </div>
                <div className="md:col-start-7 md:col-end-11 font-light">
                  <div className="font-medium mb-2"> title->React.string </div>
                  <div> name->React.string </div>
                  {switch (phoneNumber) {
                   | None => React.null
                   | Some(pn) =>
                     <a
                       className="font-light block"
                       href={"tel:" ++ Telefonnummer.Normalize.clean(pn)}>
                       pn->React.string
                     </a>
                   }}
                  <Mailto email />
                </div>
              </div>
            )
          ->Belt.List.toArray
          ->React.array}
       </div>
     | _ =>
       <div
         className="grid md:grid-columns-4 grid-gap-8-x col-start-2 col-end-2">
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
       </div>
     }}
  </div>;
};
