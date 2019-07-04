[@react.component]
let make = (~data, ~illustrationGroup, ~illustrationShare) => {
  let page = Page.HowWeWork.make(data);

  <>
    <Gatsby.Link className=None _to="/"> "Start"->React.string </Gatsby.Link>
    <div
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24">
      <Block.Text title={page.teamTitle}> {page.teamText} </Block.Text>
      <Block.Illustration src=illustrationGroup />
      <Block.Text title={page.methodTitle}> {page.methodText} </Block.Text>
    </div>
    <Block.Section color=`Concrete>
      <div
        className="grid md:grid-columns-2 grid-gap-8-x col-start-2 col-end-2">
        <div> <Typography.H3> {page.hiringTitle} </Typography.H3> </div>
        <div>
          <Typography.H4> {page.openApplicationHeader} </Typography.H4>
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
