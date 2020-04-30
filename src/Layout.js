import { graphql, useStaticQuery } from 'gatsby'
import * as React from 'react'
import Footer from '../lib/js/re/components/Footer'
import MobileNavigation from '../lib/js/re/components/MobileNavigation'
import './index.css'
import Closr from '../lib/js/re/components/Closr'

const Layout = ({ children }) => {
  const data = useStaticQuery(graphql`
    query Addresses {
      allContentfulAdresser(filter: { node_locale: { eq: "sv-SE" } }) {
        nodes {
          city
          address1
          contactPhone
          contactMail
          orgNumber
          zip
          title
        }
      }
      socialMediaIcons: allFile(
        filter: { relativePath: { regex: "/icon-/" } }
      ) {
        nodes {
          name
          publicURL
        }
      }
    }
  `)

  console.log(`

██╗████████╗███████╗ █████╗ ███╗   ███╗
██║╚══██╔══╝██╔════╝██╔══██╗████╗ ████║
██║   ██║   █████╗  ███████║██╔████╔██║
██║   ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║
██║   ██║   ███████╗██║  ██║██║ ╚═╝ ██║
╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝

  `)

  return (
    <>
      <MobileNavigation />
      {children}
      <Footer
        locations={data.allContentfulAdresser.nodes}
        socialMedia={data.socialMediaIcons.nodes}
      />
      <Closr url={"https://chatbot.sirchat.iteamdev.se/?accountId=63c85932-3b31-483a-9b9c-897505aebb87"} />
    </>
  )
}

export default Layout
