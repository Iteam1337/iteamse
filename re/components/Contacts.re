[@react.component]
let make = (~contacts: list(Page.Employee.t), ~title=?) => {
  <div>
    {switch (title) {
     | None => React.null
     | Some(title) =>
       <div className="mb-12"> <Typography.H2> title </Typography.H2> </div>
     }}
    {switch (Belt.List.length(contacts)) {
     | 2 =>
       <div
         className="grid md:grid-columns-2 grid-gap-8 col-start-2 col-end-2">
         {contacts
          ->Belt.List.map(({title, short, avatar, email, name, phoneNumber}) =>
              <div
                className="grid md:grid-columns-10 items-center
              justify-center text-center md:text-left"
                key=name>
                <div className="mb-5 md:mb-0 md:col-start-1 md:col-end-5">
                  <Gatsby.Link
                    className={Some("flex justify-center items-start")}
                    _to={"/medarbetare/" ++ short}>
                    {switch (avatar) {
                     | None => <Avatar.Gravatar email />
                     | Some(src) => <Avatar.Contentful src />
                     }}
                  </Gatsby.Link>
                </div>
                <div className="md:col-start-6 md:col-end-11 font-light">
                  <div className="font-medium mb-2"> title->React.string </div>
                  <div>
                    <Gatsby.Link className=None _to={"/medarbetare/" ++ short}>
                      name->React.string
                    </Gatsby.Link>
                  </div>
                  {switch (phoneNumber) {
                   | None => React.null
                   | Some(pn) =>
                     <a
                       className="font-light block"
                       href={Telefonnummer.Link.make(pn)}>
                       pn->React.string
                     </a>
                   }}
                  <Contact.Mailto email />
                </div>
              </div>
            )
          ->Belt.List.toArray
          ->React.array}
       </div>
     | _ =>
       <div
         className="grid md:grid-columns-4 grid-gap-8 col-start-2 col-end-2">
         {contacts
          ->Belt.List.map(({title, avatar, email, name, short}) =>
              <div
                className="flex flex-col items-center justify-between text-center"
                key=name>
                <div className="font-medium"> title->React.string </div>
                <div>
                  <Gatsby.Link
                    className={Some("flex justify-center items-start my-5")}
                    _to={"/medarbetare/" ++ short}>
                    {switch (avatar) {
                     | None => <Avatar.Gravatar email />
                     | Some(src) => <Avatar.Contentful src />
                     }}
                  </Gatsby.Link>
                  <div className="font-medium">
                    <Gatsby.Link className=None _to={"/medarbetare/" ++ short}>
                      name->React.string
                    </Gatsby.Link>
                  </div>
                  <Contact.Mailto email />
                </div>
              </div>
            )
          ->Belt.List.toArray
          ->React.array}
       </div>
     }}
  </div>;
};
