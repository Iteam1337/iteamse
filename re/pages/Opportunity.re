[@react.component]
let make = (~data) => {
  let page = Page.Opportunity.make(data);

  Block.(
    <>
      <Header
        backgroundImage={page.header.url}
        backgroundFluid={page.header.localFile}
        color={page.header.textBgColor}
        messageOne={page.title}
        messageTwo={Some(page.location)}
        messageTwoLight=true
      />
      <Container>
        <Breadcrumbs title={page.title} />
        <Text title={page.roleTitle}> {page.role} </Text>
        <Text title={page.knowledgeTitle}> {page.knowledge} </Text>
        <Text title={page.bonusKnowledgeTitle}> {page.bonusKnowledge} </Text>
        <Text title={page.aboutUsTitle}> {page.aboutUs} </Text>
        <Text title={page.perksTitle}> {page.perks} </Text>
        <Text title={page.technicalitiesTitle}> {page.technicalities} </Text>
        <Text title={page.applicationTitle}> {page.application} </Text>
      </Container>
      <Section color=`Aquamarine>
        <Contacts contacts={page.contacts} title={page.contactTitle} />
      </Section>
    </>
  );
};

let default = make;
