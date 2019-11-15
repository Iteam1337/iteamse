[@react.component]
let make = (~ads, ~data, ~illustrationGroup, ~illustrationShare) => {
  let page = Page.HowWeWork.make(data);

  Block.(
    <>
      <Header
        backgroundImage={page.header.url}
        backgroundFluid={page.header.localFile}
        color={page.header.textBgColor}
        messageOne={page.header.text}
      />
      <Container>
        <Text title={page.teamTitle}> {page.teamText} </Text>
        <Illustration src=illustrationGroup />
        <Text title={page.methodTitle}> {page.methodText} </Text>
      </Container>
      <Section color=`Concrete>
        <div className="grid md:grid-columns-2 grid-gap-8-x">
          <div>
            <div className="mb-4">
              <Typography.H3> {page.hiringTitle} </Typography.H3>
            </div>
            {ads
             ->Belt.List.fromArray
             ->Belt.List.map(ad =>
                 <div className="mb-4">
                   <Link url={"/karriar/" ++ ad##urlId}>
                     {React.string(ad##title)}
                   </Link>
                   {React.string(" (" ++ ad##location ++ ")")}
                 </div>
               )
             ->Belt.List.toArray
             ->React.array}
          </div>
          <div>
            <Typography.H4 className="mb-4">
              {page.openApplicationHeader}
            </Typography.H4>
            <Markdown source={page.openApplicationText} />
          </div>
        </div>
      </Section>
      <div
        className="grid-columns-iteam grid-gap-10-y grid md:grid-gap-24-y mb-10 md:mb-24">
        <Gatsby.FluidImg
          className={Some("col-bleed w-full")}
          fluid=data##imageBleed##fluid
        />
        <Text title={page.sharingTitle}> {page.sharingText} </Text>
        <Illustration src=illustrationShare />
        <Text title={page.customersTitle}> {page.customersText} </Text>
      </div>
      <Section color=`CornflowerBlue>
        <Contacts contacts={page.contacts} title={page.contactTitle} />
      </Section>
    </>
  );
};

let default = make;
