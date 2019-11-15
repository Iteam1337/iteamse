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

  Block.(
    <>
      <StartpageHeader
        backgroundImage=greenBlob
        illustrationIteamI
        title={page.headerText1}
        lead={page.headerLead}
      />
      <Container>
        <Text title={page.weAreTitle}> {page.weAreText} </Text>
        <Text title={page.weOfferTitle}> {page.weOfferText} </Text>
        <Illustration src=illustrationGroup />
        <Text title={page.ourMethodTitle}> {page.ourMethodText} </Text>
      </Container>
      <Section color=`Concrete>
        <CTA
          illustration=illustrationCrane
          button={page.ctaButton}
          title={page.ctaTitle}>
          {page.ctaText}
        </CTA>
      </Section>
      <Section color=`RadicalRed>
        <Contacts contacts={page.contacts} />
      </Section>
    </>
  );
};

let default = make;
