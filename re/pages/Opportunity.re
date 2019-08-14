[@react.component]
let make = (~data) => {
  let page = Page.Opportunity.make(data);

  <>
    <Block.Header
      backgroundImage={page.header.url}
      color={page.header.textBgColor}
      messageOne={page.title}
      messageTwo={Some(page.location)}
      messageTwoLight=true
    />
    <Container>
      <Breadcrumbs title={page.title} />
      <Block.Text title={page.roleTitle}> {page.role} </Block.Text>
      <Block.Text title={page.knowledgeTitle}> {page.knowledge} </Block.Text>
      <Block.Text title={page.bonusKnowledgeTitle}>
        {page.bonusKnowledge}
      </Block.Text>
      <Block.Text title={page.aboutUsTitle}> {page.aboutUs} </Block.Text>
      <Block.Text title={page.perksTitle}> {page.perks} </Block.Text>
      <Block.Text title={page.technicalitiesTitle}>
        {page.technicalities}
      </Block.Text>
      <Block.Text title={page.applicationTitle}>
        {page.application}
      </Block.Text>
    </Container>
    <Block.Section color=`Aquamarine>
      <Contacts contacts={page.contacts} title={page.contactTitle} />
    </Block.Section>
  </>;
};

let default = make;
