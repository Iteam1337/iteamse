import * as React from 'react'
import Footer from '../lib/js/re/components/Footer'
import { graphql, useStaticQuery } from 'gatsby'

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
      {children}
      <Footer
        locations={data.allContentfulAdresser.nodes}
        socialMedia={data.socialMediaIcons.nodes}
      />
    </>
  )
}

export default Layout
