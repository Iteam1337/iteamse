module AddressBlock = {
  [@react.component]
  let make = (~location) => {
    let {title, address, postalAddress, orgNumber, email}: Address.t =
      Address.make(location);

    <div>
      <div className="font-medium mb-5"> {React.string(title)} </div>
      <div className="mb-5">
        <div> {React.string(address)} </div>
        <div> {React.string(postalAddress)} </div>
      </div>
      <Contact.Mailto email />
      <div className="mt-1"> {"ORG: " ++ orgNumber |> React.string} </div>
    </div>;
  };
};

module SocialMediaBlock = {
  [@react.component]
  let make = (~socialMedia) => {
    let {name, icon, href}: SocialMedia.t = SocialMedia.make(socialMedia);

    <li className="list-no-dots flex items-center">
      <img className="mr-4" src=icon alt="" />
      <a target="_blank" rel="noopener noreferrer" className="" href key=name>
        {React.string(name)}
      </a>
    </li>;
  };
};

[@react.component]
let make = (~locations, ~socialMedia) => {
  <Block.Section color=`Concrete>
    <div className="grid md:grid-columns-3 grid-gap-8">
      Belt.List.(
        locations
        ->fromArray
        ->map(location => <AddressBlock location key=location##zip />)
        ->toArray
        ->React.array
      )
      <div>
        <div className="font-medium mb-5">
          {React.string({j|Följ oss|j})}
        </div>
        <ul className="list-none">
          Belt.List.(
            socialMedia
            ->fromArray
            ->map(socialMedia =>
                <SocialMediaBlock key=socialMedia##name socialMedia />
              )
            ->toArray
            ->React.array
          )
        </ul>
      </div>
    </div>
  </Block.Section>;
};

let default = make;
