[@react.component]
let make = (~ads, ~data, ~illustrationGroup, ~illustrationShare) => {
  let page = Page.HowWeWork.make(data);

  <>
    <Block.Header
      backgroundImage={page.header.url}
      color={page.header.textBgColor}
      messageOne={page.header.text}
    />
    <div
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid
      md:grid-gap-24-y my-10 md:my-24">
      <Block.Text title={page.teamTitle}> {page.teamText} </Block.Text>
      <Block.Illustration src=illustrationGroup />
      <Block.Text title={page.methodTitle}> {page.methodText} </Block.Text>
    </div>
    <Block.Section color=`Concrete>
      <div
        className="grid md:grid-columns-2 grid-gap-8-x col-start-2 col-end-2">
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
          <Block.Markdown source={page.openApplicationText} />
        </div>
      </div>
    </Block.Section>
    <div
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y mb-24">
      <Block.Image src={page.imageBleed} />
      <Block.Text title={page.sharingTitle}> {page.sharingText} </Block.Text>
      <Block.Illustration src=illustrationShare />
      <Block.Text title={page.customersTitle}>
        {page.customersText}
      </Block.Text>
    </div>
    <Block.Section color=`CornflowerBlue>
      <Contacts contacts={page.contacts} title={page.contactTitle} />
    </Block.Section>
  </>;
};

let default = make;
