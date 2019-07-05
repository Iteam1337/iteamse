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
      <div className="font-medium mt-5 text-lg">
        <Gatsby.Link className=None _to={"/medarbetare/" ++ short}>
          name->React.string
        </Gatsby.Link>
      </div>
      <div className="font-normal my-1 text-md"> title->React.string </div>
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

  let (locationFilter, setLocation) = React.useState(_ => `All);

  let matchesLocationFilter = (currentFilter, employee: Page.Employee.t) =>
    switch (currentFilter, employee) {
    | (`All, _) => true
    | (_, {location}) when location == currentFilter => true
    | _ => false
    };

  <>
    <Block.Header
      backgroundImage={page.header.url}
      color={page.header.textBgColor}
      messageOne={page.header.text}
    />
    <div className="grid grid-columns-1fr md:grid-columns-1024">
      <div
        className="grid-gap-2-y grid md:grid-columns-12 col-start-2
      col-end-2 grid-gap-8-x pt-24">
        <div
          className=Css.(
            merge([
              "md:col-start-1 md:col-end-12",
              Theme.Colors.textFromType(`CornflowerBlue),
            ])
          )>
          {Location.asList
           ->Belt.List.map(area =>
               <span
                 className=Css.(
                   merge([
                     "mr-4",
                     locationFilter == area ? "font-medium" : "",
                   ])
                 )
                 key={area |> Location.toString}
                 onKeyUp={event =>
                   ReactEvent.Keyboard.keyCode(event) == 13
                     ? setLocation(_ => area) : ()
                 }
                 onClick={_ => setLocation(_ => area)}
                 tabIndex=0
                 role="button">
                 {area->Location.toString->React.string}
               </span>
             )
           ->Belt.List.toArray
           ->React.array}
        </div>
      </div>
      <div
        className="grid md:grid-columns-4 grid-gap-8 col-start-2 col-end-2 my-24">
        {coworkers
         ->Page.Employee.fromArray
         ->Belt.List.keep(employee =>
             matchesLocationFilter(locationFilter, employee)
           )
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
