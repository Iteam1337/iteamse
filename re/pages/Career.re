[@react.component]
let make = (~data) => {
  let {
    contactTitle,
    header,
    openApplicationLabel,
    openApplicationText,
    contacts,
    opportunities,
  }: Page.Career.t =
    Page.Career.make(data);

  Block.(
    <>
      <Header
        backgroundImage={header.url}
        backgroundFluid={header.localFile}
        color={header.textBgColor}
        messageOne={header.text}
      />
      <Container>
        {opportunities
         ->Belt.List.map(opportunity =>
             <Block.Element
               key={opportunity.id}
               title={`Text(opportunity.title)}
               subtitle={opportunity.location}>
               <Block.Markdown source={opportunity.role} />
               <Link
                 ariaLabel={j|Läs mer om annonsen för $opportunity.title|j}
                 url={"/karriar/" ++ opportunity.urlId}>
                 {React.string({j|Läs mer och ansök|j})}
               </Link>
             </Block.Element>
           )
         ->Belt.List.toArray
         ->React.array}
        <Element title={`Text(openApplicationLabel)}>
          <Markdown source=openApplicationText />
        </Element>
      </Container>
      <Section color=`RadicalRed>
        <Contacts title=contactTitle contacts />
      </Section>
    </>
  );
};

let default = make;
