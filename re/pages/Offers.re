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
      color={header.textBgColor}
      messageOne={header.text}
    />
    <div
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid
      md:grid-gap-24-y py-10 md:py-24">
      <div className="col-start-2 col-end-2">
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
    </div>
    {offers
     ->Belt.List.fromArray
     ->Belt.List.map(Offer.make)
     ->Belt.List.mapWithIndex((i, offer) =>
         <Block.Section color={i mod 2 === 0 ? `Concrete : `White}>
           <div
             className="col-start-2 col-end-2"
             id={offer.title->Js.String.toLowerCase->Js.String.trim}>
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