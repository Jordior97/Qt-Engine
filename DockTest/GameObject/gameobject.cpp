#include "gameobject.h"
#include "Component/transform.h"
#include "Component/shaperenderer.h"
#include "Component/meshrenderer.h"
#include <QJsonArray>
#include <QJsonObject>


GameObject::GameObject()
{
    name = "GameObject";

    Transform *myTransform = new Transform(this);
    components.push_back(myTransform);
}

void GameObject::Read(const QJsonObject &json)
{
    // Read Base Info
    name = json["name"].toString();
    active = json["isActive"].toBool();
    visible = json["isVisible"].toBool();

    // Read Component
    QJsonArray compArray = json["components"].toArray();
    for(int i=0; i < compArray.size(); i++)
    {
        QJsonObject compObject = compArray[i].toObject();
        components[i]->Read(compObject);
    }
}

void GameObject::Write(QJsonObject &json) const
{
    // Save Components Info
    QJsonArray compArray;
    foreach (Component* comp, components)
    {
        QJsonObject compObject;
        comp->Write(compObject);
        compArray.append(compObject);
    }
    json["components"] = compArray;

    // Save Base Info
    json["name"] = name;
    json["isActive"] = active;
    json["isVisible"] = visible;
}


MeshRenderer* GameObject::AddMesh(Shape shape, const char* model)
{
     MeshRenderer *myMeshRenderer = new MeshRenderer(this, shape, model);
     components.push_back(myMeshRenderer);

     return myMeshRenderer;
}

Transform* GameObject::GetTransform()
{
    for(int i =0;i<components.size();i++)
    {
        if(components[i]->type== Type::COMP_TRANSFORM)
        {
            return (Transform*)components[i];
        }
    }
    return nullptr;
}

Component* GameObject::GetComponent(Type type)
{
    for(int i =0;i<components.size();i++)
    {
        if(components[i]->type== type)
        {
            return components[i];
        }
    }
    return nullptr;
}
