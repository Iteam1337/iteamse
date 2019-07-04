[@react.component]
let make = (~data) => {
  let page = Page.Coworker.make(data);

  <div
    className="grid grid-columns-1fr md:grid-columns-1024 grid-gap-10-y md:grid-gap-24-y my-24">
    <Block.Element title="Kontakt">
      <div> page.phoneNumber->React.string </div>
      <div> page.email->React.string </div>
    </Block.Element>
    <Block.Text title={page.whyTitle}> {page.why} </Block.Text>
    <Block.Text title={page.backgroundTitle}> {page.background} </Block.Text>
    <Block.Text title={page.competenceTitle}> {page.competence} </Block.Text>
  </div>;
};

let default = make;
