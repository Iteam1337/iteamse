[@react.component]
let make = (~data, ~socialMedia) => {
  <Block.Section color=`Concrete>
    <div className="col-start-2 col-end-2 grid md:grid-columns-3 grid-gap-8">
      {data
       ->Belt.List.fromArray
       ->Belt.List.map(Address.make)
       ->Belt.List.map(
           ({title, address, city, zip, orgNumber, phoneNumber, email}) =>
           <div key=zip>
             <div className="font-medium mb-5"> title->React.string </div>
             <div className="mb-5">
               <div> address->React.string </div>
               <div> {zip ++ " " ++ city |> React.string} </div>
             </div>
             <a
               className="font-light block mb-1"
               href={"tel:" ++ Telefonnummer.Normalize.clean(phoneNumber)}>
               phoneNumber->React.string
             </a>
             <Mailto email />
             <div className="mt-1">
               {"ORG: " ++ orgNumber |> React.string}
             </div>
           </div>
         )
       ->Belt.List.toArray
       ->React.array}
      <div>
        <div className="font-medium mb-5"> {j|Följ oss|j}->React.string </div>
        <ul className="list-none">
          {socialMedia
           ->Belt.List.fromArray
           ->Belt.List.map(SocialMedia.make)
           ->Belt.List.map(({name, icon, href}) =>
               <li className="list-no-dots flex items-center" key=name>
                 <img className="mr-4" src=icon alt="" />
                 <a
                   target="_blank"
                   rel="noopener noreferrer"
                   className=""
                   href
                   key=name>
                   name->React.string
                 </a>
               </li>
             )
           ->Belt.List.toArray
           ->React.array}
        </ul>
      </div>
    </div>
  </Block.Section>;
};

let default = make;
