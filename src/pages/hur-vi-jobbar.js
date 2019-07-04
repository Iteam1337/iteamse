import React from 'react'
import { StaticQuery, graphql, useStaticQuery } from 'gatsby'
import HowWeWork from '../../lib/js/re/pages/HowWeWork'

export default () => {
  const data = useStaticQuery(graphql`
    query HowWeWork {
      contentfulSidaHurViJobbar {
        methodTitle
        methodText {
          methodText
        }
        sharingText {
          sharingText
        }
        sharingTitle
        teamText {
          teamText
        }
        teamTitle
        customersText {
          customersText
        }
        imageBleed {
          file {
            url
          }
        }
        customersTitle
        contactTitle
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
          phoneNumber
        }
        hiringTitle
        openApplicationText {
          openApplicationText
        }
        openApplicationHeader
      }
      illustrationGroup: file(relativePath: { eq: "illustration-group.svg" }) {
        publicURL
      }
      illustrationShare: file(relativePath: { eq: "illustration-share.svg" }) {
        publicURL
      }
      allContentfulAnnonser(filter: { node_locale: { eq: "sv-SE" } }) {
        nodes {
          title
          location
        }
      }
    }
  `)

  return (
    <HowWeWork
      data={data.contentfulSidaHurViJobbar}
      illustrationGroup={data.illustrationGroup.publicURL}
      illustrationShare={data.illustrationShare.publicURL}
    />
  )
}
