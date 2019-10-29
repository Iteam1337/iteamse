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

  <>
    <Block.Header
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
             title={opportunity.title}
             subtitle={opportunity.location}>
             <Block.Markdown source={opportunity.role} />
             <Link url={"/karriar/" ++ opportunity.urlId}>
               {React.string({j|Läs mer och ansök|j})}
             </Link>
           </Block.Element>
         )
       ->Belt.List.toArray
       ->React.array}
      <Block.Element title=openApplicationLabel>
        <Block.Markdown source=openApplicationText />
      </Block.Element>
    </Container>
    <Block.Section color=`RadicalRed>
      <Contacts title=contactTitle contacts />
    </Block.Section>
  </>;
};

let default = make;
