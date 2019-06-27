import httplib2
import json

def getGeocodeLocation(inputString):
  google_api_key = "API_KEY_HERE"
  locationString = inputString.replace(" ", "+")
  url = ('https://map.googleapis.com/maps/api/geocode/json?address=%s&key=%s'%(locationString, google_api_key))
  h = httplib2.Http()
  response, content = h.request(url, 'GET')
  result = json.loads(content)
  latitude = result['result'][0]['geometry']['location']['lat']
  longitude = result['result'][0]['geometry']['location']['lng']
  return (latitude, longitude)