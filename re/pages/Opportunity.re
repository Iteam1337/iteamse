[@react.component]
let make = (~data) => {
  let page = Page.Opportunity.make(data);

  <>
    <Block.Header
      backgroundImage={page.header.url}
      color={page.header.textBgColor}
      messageOne={page.title}
      messageTwo={Some(page.location)}
    />
    <div
      className="grid grid-columns-1fr md:grid-columns-1024 grid-gap-10-y md:grid-gap-24-y my-24">
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
    </div>
    <Block.Section color=`Aquamarine>
      <Contacts contacts={page.contacts} title={page.contactTitle} />
    </Block.Section>
  </>;
};

let default = make;
