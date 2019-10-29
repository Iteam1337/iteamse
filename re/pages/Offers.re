[@react.component]
let make = (~data, ~offers) => {
  let {header, intro, contacts, contactTitle}: Page.Offers.t =
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
        {React.string(intro)}
        <div
          className=Css.(
            merge([
              "grid md:grid-columns-3 mt-20",
              style([gridGap(`px(60))]),
            ])
          )>
          {miniUsps
           ->Belt.List.map(usp =>
               <div className="grid grid-gap-5">
                 <img className="h-32" src={usp.illustration} alt="" />
                 <Typography.H3> {usp.title} </Typography.H3>
                 <div> {React.string(usp.text)} </div>
                 <a
                   className="border-b-2 border-solid border-current text-lg
                   text-cornflower-blue justify-self-start"
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
         <Block.Section color={i mod 2 === 0 ? `Concrete : `White}>
           <div id={offer.title->Js.String.toLowerCase->Js.String.trim}>
             <Typography.H1> {React.string(offer.title)} </Typography.H1>
             <div className="mt-4"> {React.string(offer.lead)} </div>
             <div
               className="grid md:grid-columns-2 my-8 md:my-20 grid-gap-4-y md:grid-gap-12-y">
               {offer.usps
                ->Belt.List.map(usp =>
                    <div>
                      <Typography.H3> {usp.title} </Typography.H3>
                      <div className="mt-4"> {React.string(usp.text)} </div>
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
