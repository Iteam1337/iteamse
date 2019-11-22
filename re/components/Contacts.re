module Layout = {
  type t = [ | `Normal | `Centered];
};

module Contact = {
  [@react.component]
  let make = (~employee) => {
    let {title, avatar, email, name, short, location}: Page.Employee.t = employee;

    <div
      className="flex flex-col items-center flex-none text-center ml-6 mr-6"
      key=name>
      <div className="font-medium"> title->React.string </div>
      <div>
        <Gatsby.Link
          ariaLabel={j|Gå till medarbetar-sidan för $name|j}
          className={Some("flex justify-center items-start my-5")}
          _to={"/medarbetare/" ++ short}>
          {switch (avatar) {
           | None => <Avatar.Gravatar email />
           | Some(src) => <Avatar.Contentful src />
           }}
        </Gatsby.Link>
        <div className="font-medium">
          <Gatsby.Link
            ariaLabel={j|Gå till medarbetar-sidan för $name|j}
            className=None
            _to={"/medarbetare/" ++ short}>
            name->React.string
          </Gatsby.Link>
        </div>
        <div className="text-sm">
          {React.string(Location.toString(location))}
        </div>
        <Contact.Mailto email />
      </div>
    </div>;
  };
};

[@react.component]
let make =
    (
      ~contacts: list(Page.Employee.t),
      ~title=?,
      ~layout: Layout.t=`Centered,
      ~subtitle=None,
    ) => {
  <div>
    {switch (title) {
     | Some(title) =>
       <div
         className={Cn.make([
           "mb-12",
           switch (layout) {
           | `Normal => ""
           | `Centered => "text-center"
           },
         ])}>
         <Typography.H2> title </Typography.H2>
         {switch (subtitle) {
          | Some(subtitle) =>
            <div className="mt-3"> {React.string(subtitle)} </div>
          | None => React.null
          }}
       </div>
     | None => React.null
     }}
    <div className="flex flex-wrap justify-center">
      {contacts
       ->Belt.List.map(employee => <Contact key={employee.name} employee />)
       ->Belt.List.toArray
       ->React.array}
    </div>
  </div>;
};