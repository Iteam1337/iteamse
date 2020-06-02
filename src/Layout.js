import { graphql, useStaticQuery } from 'gatsby'
import * as React from 'react'
import Footer from '../lib/js/re/components/Footer'
import MobileNavigation from '../lib/js/re/components/MobileNavigation'
import './index.css'
import { Helmet } from 'react-helmet'

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
    <Helmet>
    <script src="https://chatbot.sirchat.iteamdev.se/closr.min.js" />
        <script type="text/javascript">
          {`setTimeout(() => {Closr.init({ accountId: "92946072-0cf0-43ec-98dc-aa8a5d0c0e46" })}, 500)`}
        </script>
    </Helmet>
      <MobileNavigation />
      {children}
      <Footer
        locations={data.allContentfulAdresser.nodes}
        socialMedia={data.socialMediaIcons.nodes}
      />
    </>
  )
}

export default Layout
