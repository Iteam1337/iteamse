import React from 'react'
import { StaticQuery, graphql, useStaticQuery } from 'gatsby'
import Index from '../../lib/js/re/pages/Index'
import '../index.css'

export default () => {
  const data = useStaticQuery(graphql`
    query Start {
      contentfulSidaStartsida2019 {
        weAreTitle
        weAreText {
          weAreText
        }
        weOfferText {
          weOfferText
        }
        weOfferTitle
        ourMethodText {
          ourMethodText
        }
        ourMethodTitle
        contacts {
          avatar {
            file {
              url
            }
          }
          email
          name
          short
          title
        }
      }
      illustration: file(relativePath: { eq: "illustrations-group.svg" }) {
        publicURL
      }
    }
  `)

  return (
    <Index
      data={data.contentfulSidaStartsida2019}
      illustration={data.illustration.publicURL}
    />
  )
}
