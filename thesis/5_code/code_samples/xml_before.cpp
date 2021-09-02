XMLTag*  XMLDocument::m_findTagById(const XMLTag & tag, const std::string & tagName, 
                                    const std::string & idValue) const
{
    for(XMLTag::NestedTags::const_iterator j = tag.getNestedTags().begin(); 
        j != tag.getNestedTags().end(); j++)
    {
        if(j->second->getName() == tagName 
        && j->second->getAttributeValue("id") == idValue)
            return j->second;
        else
            // rezultat rekurencyjnego wywołania nie jest brany pod uwagę
            m_findTagById(*(j->second), tagName, idValue);
    }
    return 0;
}

