XMLTag* XMLDocument::findTagById(const XMLTag& startingTag, 
                                 const std::string& tagName, 
                                 const std::string& idValue) const
{
    const XMLTag::NestedTags& nestedTags = startingTag.getNestedTags();
    for(const auto& nestedTag: nestedTags)
    {
        if((nestedTag.second->getName() == tagName) 
            && (nestedTag.second->getAttributeValue("id") == idValue))
        {
            return nestedTag.second;
        }
    }
    return nullptr;
}
