import { graphql, useStaticQuery } from 'gatsby'
import * as React from 'react'
import Footer from '../lib/js/re/components/Footer'
import MobileNavigation from '../lib/js/re/components/MobileNavigation'
import './index.css'

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
      socialMediaIcons: allFile(filter: { relativePath: { regex: "/icon/" } }) {
        nodes {
          name
          publicURL
        }
      }
    }
  `)

  return (
    <>
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
