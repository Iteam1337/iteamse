[@react.component]
let make = (~data, ~offers) => {
  let {header, intro, contacts, contactTitle}: Page.Offers.t =
    Page.Offers.make(data);

  <>
    <Block.Header
      backgroundImage={header.url}
      color={header.textBgColor}
      messageOne={header.text}
    />
    <div
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24">
      <div className="col-start-2 col-end-2"> {React.string(intro)} </div>
    </div>
    {offers
     ->Belt.List.fromArray
     ->Belt.List.map(Offer.make)
     ->Belt.List.mapWithIndex((i, offer) =>
         <Block.Section color={i mod 2 === 0 ? `Concrete : `White}>
           <div className="col-start-2 col-end-2">
             <Typography.H1> {React.string(offer.title)} </Typography.H1>
             <div className="mt-4"> {React.string(offer.lead)} </div>
             <div
               className=Css.(
                 merge([
                   "grid md:grid-columns-2 my-20",
                   style([gridGap(`px(60))]),
                 ])
               )>
               {offer.usps
                ->Belt.List.map(usp =>
                    <div>
                      <Typography.H3> {usp.title} </Typography.H3>
                      <div> {React.string(usp.text)} </div>
                    </div>
                  )
                ->Belt.List.toArray
                ->React.array}
             </div>
             <img
               className="mx-auto block w-2/3 md:w-1/2"
               src={offer.illustration}
               alt=""
             />
           </div>
         </Block.Section>
       )
     ->Belt.List.toArray
     ->React.array}
    <Block.Section color=`Aquamarine>
      <Contacts title=contactTitle contacts />
    </Block.Section>
  </>;
};

let default = make;
