module Coworker = {
  [@react.component]
  let make = (~coworker) => {
    let {avatar, email, short, name, title, phoneNumber}: Page.Employee.t = coworker;

    <div className="text-center flex flex-col justify-between items-center">
      <Gatsby.Link
        className={Some("flex justify-center items-start")}
        _to={"/medarbetare/" ++ short}>
        {switch (avatar) {
         | None => <Avatar.Gravatar email />
         | Some(src) => <Avatar.Contentful src />
         }}
      </Gatsby.Link>
      <div className="font-medium mt-5">
        <Gatsby.Link className=None _to={"/medarbetare/" ++ short}>
          name->React.string
        </Gatsby.Link>
      </div>
      <div className="font-normal my-1 text-sm"> title->React.string </div>
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
    </div>;
  };
};

[@react.component]
let make = (~coworkers, ~data) => {
  let page = Page.Coworkers.make(data);

  <>
    <Block.Header
      backgroundImage={page.header.url}
      color={page.header.textBgColor}
      messageOne={page.header.text}
    />
    <div className="grid grid-columns-1fr md:grid-columns-1024">
      <div
        className="grid md:grid-columns-4 grid-gap-8 col-start-2 col-end-2 my-24">
        {coworkers
         ->Page.Employee.fromArray
         ->Belt.List.map(coworker => <Coworker coworker key={coworker.name} />)
         ->Belt.List.toArray
         ->React.array}
      </div>
      <Block.Section color=`RadicalRed>
        <Contacts contacts={page.contacts} title={page.contactTitle} />
      </Block.Section>
    </div>
  </>;
};

let default = make;
