[@react.component]
let make = (~data) => {
  let page = Page.Coworker.make(data);

  Block.(
    <>
      <Header
        backgroundImage={page.header.url}
        backgroundFluid={page.header.localFile}
        color={page.header.textBgColor}
        messageOne={page.name}
        messageTwo={Some(page.title)}
        messageTwoLight=true
      />
      <Container>
        <Breadcrumbs title={page.name} />
        <Element title={`Text("Kontakt")}>
          {page.phoneNumber
           ->Belt.Option.map(phoneNumber =>
               <Contact.Telephone className="text-lg" phoneNumber />
             )
           ->Belt.Option.getWithDefault(React.null)}
          <Contact.Mailto
            className="text-lg text-cornflower-blue"
            email={page.email}
          />
        </Element>
        <Text title={page.whyTitle}> {page.why} </Text>
        <Text title={page.backgroundTitle}> {page.background} </Text>
        <Text title={page.competenceTitle}> {page.competence} </Text>
      </Container>
    </>
  );
};

let default = make;
