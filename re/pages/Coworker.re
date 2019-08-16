[@react.component]
let make = (~data) => {
  let page = Page.Coworker.make(data);

  <>
    <Block.Header
      backgroundImage={page.header.url}
      color={page.header.textBgColor}
      messageOne={page.name}
      messageTwo={Some(page.title)}
      messageTwoLight=true
    />
    <Container>
      <Breadcrumbs title={page.name} />
      <Block.Element title="Kontakt">
        <Contact.Telephone
          className="text-lg"
          phoneNumber={page.phoneNumber}
        />
        <Contact.Mailto
          className="text-lg text-cornflower-blue"
          email={page.email}
        />
      </Block.Element>
      <Block.Text title={page.whyTitle}> {page.why} </Block.Text>
      <Block.Text title={page.backgroundTitle}> {page.background} </Block.Text>
      <Block.Text title={page.competenceTitle}> {page.competence} </Block.Text>
    </Container>
  </>;
};

let default = make;
