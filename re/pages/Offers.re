[@react.component]
let make = (~data, ~offers) => {
  let {header, intro, contacts, contactTitle, contactSubtitle}: Page.Offers.t =
    Page.Offers.make(data);

  let miniUsps =
    offers
    ->Belt.List.fromArray
    ->Belt.List.map(offer =>
        Offer.MiniUsp.make((
          offer##offerTitle,
          offer##offerIntroText##offerIntroText,
          offer##offerIntroImage##file##url,
        ))
      );

  <>
    <Block.Header
      backgroundImage={header.url}
      backgroundFluid={header.localFile}
      color={header.textBgColor}
      messageOne={header.text}
    />
    <Container>
      <div>
        <Block.Markdown source=intro className="w-2/3 mx-auto" />
        <div className="w-2/3 pt-4 mx-auto" id="hubspotForm" />
        <div
          className=Css.(
            merge([
              "grid md:grid-columns-3 mt-20",
              style([gridGap(`px(60))]),
            ])
          )>
          {miniUsps
           ->Belt.List.map(usp =>
               <div className="grid grid-gap-5" key={usp.title}>
                 <img className="h-32" src={usp.illustration} alt="" />
                 <Typography.H3> {usp.title} </Typography.H3>
                 <div> {React.string(usp.text)} </div>
                 <a
                   className="text-lg border-b-2 border-solid border-current text-cornflower-blue justify-self-start"
                   href={
                     "#" ++ usp.title->Js.String.toLowerCase->Js.String.trim
                   }>
                   {React.string(
                      {j|Läs mer om |j} ++ usp.title->Js.String.toLowerCase,
                    )}
                 </a>
               </div>
             )
           ->Belt.List.toArray
           ->React.array}
        </div>
      </div>
    </Container>
    {offers
     ->Belt.List.fromArray
     ->Belt.List.map(Offer.make)
     ->Belt.List.mapWithIndex((i, offer) =>
         <Block.Section
           key={offer.lead} color={i mod 2 === 0 ? `Concrete : `White}>
           <div id={offer.title->Js.String.toLowerCase->Js.String.trim}>
             <Typography.H1> {React.string(offer.title)} </Typography.H1>
             <div className="mt-4"> {React.string(offer.lead)} </div>
             <div
               className="my-8 grid md:grid-columns-2 md:my-20 grid-gap-4 md:grid-gap-12-y">
               {offer.usps
                ->Belt.List.map(usp =>
                    <div key={usp.text}>
                      <Typography.H3> {usp.title} </Typography.H3>
                      <div className="mt-4"> {React.string(usp.text)} </div>
                    </div>
                  )
                ->Belt.List.toArray
                ->React.array}
             </div>
             <img
               className="block w-2/3 mx-auto md:w-1/2"
               src={offer.illustration}
               alt=""
             />
           </div>
         </Block.Section>
       )
     ->Belt.List.toArray
     ->React.array}
    <Block.Section color=`Aquamarine>
      <Contacts title=contactTitle contacts subtitle=contactSubtitle />
    </Block.Section>
  </>;
};

let default = make;
