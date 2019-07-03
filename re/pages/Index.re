type t = {
  .
  "weAreTitle": string,
  "weAreText": {. "weAreText": string},
  "weOfferTitle": string,
  "weOfferText": {. "weOfferText": string},
  "ourMethodTitle": string,
  "ourMethodText": {. "ourMethodText": string},
  "contacts": array(Types.employee),
};

module Style = {
  open Css;

  let main =
    style([
      display(`grid),
      gridTemplateColumns([`fr(1.0), `px(1024), `fr(1.0)]),
      gridRowGap(`px(100)),
      media(
        Theme.Breakpoints.fromType(`Mobile),
        [
          gridTemplateColumns([`px(20), `fr(1.0), `px(20)]),
          gridRowGap(`px(40)),
        ],
      ),
    ]);
};

[@react.component]
let make = (~data: t, ~illustration) => {
  <>
    <main className=Style.main>
      <Block.Text title={data##weAreTitle}>
        {data##weAreText##weAreText}
      </Block.Text>
      <Block.Text title={data##weOfferTitle}>
        {data##weOfferText##weOfferText}
      </Block.Text>
      <Block.Illustration src=illustration />
      <Block.Text title={data##ourMethodTitle}>
        {data##ourMethodText##ourMethodText}
      </Block.Text>
    </main>
    <Block.Section color=`CornflowerBlue>
      <Contacts employees={data##contacts} />
    </Block.Section>
    <Block.Section color=`Concrete>
      <div> {data##ourMethodText##ourMethodText->React.string} </div>
    </Block.Section>
  </>;
};

let default = make;
