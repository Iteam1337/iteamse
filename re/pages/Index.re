[@react.component]
let make =
    (
      ~data,
      ~illustrationIteamI,
      ~illustrationGroup,
      ~illustrationCrane,
      ~greenBlob,
    ) => {
  let page = Page.Start.make(data);

  <>
    <Block.StartpageHeader
      backgroundImage=greenBlob
      illustrationIteamI
      title={page.headerText1}
      lead={page.headerLead}
    />
    <Container>
      <Block.Text title={page.weAreTitle}> {page.weAreText} </Block.Text>
      <Block.Text title={page.weOfferTitle}> {page.weOfferText} </Block.Text>
      <Block.Illustration src=illustrationGroup />
      <Block.Text title={page.ourMethodTitle}>
        {page.ourMethodText}
      </Block.Text>
    </Container>
    <Block.Section color=`Concrete>
      <Block.CTA
        illustration=illustrationCrane
        button={page.ctaButton}
        title={page.ctaTitle}>
        {page.ctaText}
      </Block.CTA>
    </Block.Section>
    <Block.Section color=`RadicalRed>
      <Contacts contacts={page.contacts} />
    </Block.Section>
  </>;
};

let default = make;
